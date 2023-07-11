#include "../include/TankAI.h"

using namespace models;

TankAI::TankAI(int tankX, int tankY){

    this->selfX = tankX;
    this->selfY = tankY;

    this->nRows = HEIGHT_MAP;
	this->nColumns = WIDTH_MAP;
				
	this->bPathFound = false;
}


void TankAI::logEdges(int nVertex, int nAdj_vertex){

    std::cout << "Logging map edges" << std::endl;

    this->mapData[nVertex].push_back(nAdj_vertex);
    this->mapData[nAdj_vertex].push_back(nVertex);

}

void TankAI::logMapEdges(Map &map, Tank &player){

    int i;
    int j;

    this->vecTemp.resize(this->nRows);

		for(i = 0; i <= this->nRows; i++){

			this->vecTemp[i].resize(this->nColumns);

			for(j = 0; j <= this->nColumns; j++){
	
				this->vecTemp[i][j] = map.getTilePassable(i, j);
				//std::cout << vecTemp[i][j] << std::endl; 
			}

        }

        this->nStart = (this->nColumns * this->selfY) + this->selfX;
        this->nTarget = (this->nColumns * player.getmY()) + player.getmX();

        
			for(i = 0; i < this->nRows; i++) {

				for(j = 0; j < this->nColumns; j++) {


					if (j + 1 < this->nColumns && this->vecTemp[i][j] != 0) {

						if(this->vecTemp[i][j + 1] != 0){

							this->logEdges((this->nColumns*i)+j, (this->nColumns*i)+j+1);
							this->logEdges((this->nColumns*i)+j + 1, (this->nColumns*i)+j);
							

						} 
						
					}

					if (i + 1 < this->nRows && this->vecTemp[i][j] != 0) {

						if(this->vecTemp[i + 1][j] != 0){

							this->logEdges((this->nColumns*i)+j, (this->nColumns*(i+1))+j);
							this->logEdges((this->nColumns*(i+1))+j, (this->nColumns*i)+j);
							

						}
					}

				}	
			}

}
		
bool TankAI::searchPath(){

    	/*options of the given location, I don't need these two to be attributes of the AI as these two will be updated frequently to fill out the refData attribute, 
			  which will be the basis for logging.*/

			std::queue<int> qOption;
    		std::unordered_set<int> setCleared; //visited/cleared options
			int nCurrent = 0;

    		qOption.push(this->nStart);
    		setCleared.insert(this->nStart);

    		while (!qOption.empty() || this->bPathFound == false) {
 
        		nCurrent = qOption.front();
        		qOption.pop();

				if (nCurrent == this->nTarget) {	// once bPathfound is no longer false, the loop should end.
				this->bPathFound = true;
				}

        		for (int nAdj_vertex : this->mapData[nCurrent]) { //check mapData for connections to push to the queue of options and insert to the sets cleared.

            		if (setCleared.find(nAdj_vertex) == setCleared.end()) {
                		qOption.push(nAdj_vertex);
                		setCleared.insert(nAdj_vertex);
						this->refData[nAdj_vertex] = nCurrent;
            		}

        		}
    		}

			if(this->bPathFound == true){

				std::cout << "Path found, logging" << std::endl;

                return this->bPathFound;
			}

			else{

				std::cout << "ERROR: Invalid path" << std::endl;
                return this->bPathFound;

			}

}

char TankAI::logPath(){

    int nCurrentPos = 0;

		nCurrentPos = this->nTarget;

        while (nCurrentPos != this->nStart) { //chart and insert the values into the route vector

            	this->vecRoute.push_back(nCurrentPos);
            	nCurrentPos = this->refData[nCurrentPos];

        }

        	
		this->vecRoute.push_back(this->nStart); //finally push back the target position itself
        
        // Logs the path to the target

        for (int i = this->vecRoute.size() - 1; i > 0; i--) {

				if (this->vecRoute[i] == this->vecRoute[i - 1] + this->nColumns) { // NORTH

					return 'N';
				}

				else if (this->vecRoute[i] == this->vecRoute[i - 1] + 1) {	// WEST

					return 'W';
				}

				else if (this->vecRoute[i] == this->vecRoute[i - 1] - 1) {	// EAST

					return 'E';
				}

				else if (this->vecRoute[i] == this->vecRoute[i - 1] + this->nColumns) {	// SOUTH

					return 'S';
				}
    	}

	return ' ';	
}

