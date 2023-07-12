#include "../include/TankAI.h"
//#include "TankAI.h"

using namespace models;

TankAI::TankAI(int tankX, int tankY){

    this->selfX = tankX;
    this->selfY = tankY;

    this->nRows = HEIGHT_MAP;
	this->nColumns = WIDTH_MAP;
				
	this->bPathFound = false;


	
}


void TankAI::logEdges(int nVertex, int nAdj_vertex){

    this->mapData[nVertex].push_back(nAdj_vertex);
    this->mapData[nAdj_vertex].push_back(nVertex);


}

void TankAI::logMapEdges(Map &map, Tank &player){

	int matNodes[HEIGHT_MAP][WIDTH_MAP];
	int nIndex = 0;
    for(int i = 0; i < HEIGHT_MAP; i++){
		for(int j = 0; j < WIDTH_MAP; j++){
			matNodes[i][j] = nIndex;
			nIndex++;
		}
	}

	this->nStart = matNodes[this->selfY/24][this->selfX/24];
	this->nTarget = matNodes[(int)player.getmY()/24][(int)player.getmX()/24];

	//std::cout<< this->nStart << " " << this->nTarget;

	nIndex = 0;
	for(int i = 0; i < HEIGHT_MAP; i++){
		for(int j = 0; j < WIDTH_MAP; j++){
			
			std::vector<int> temp;

			if(map.getTilePassable(i+1,j) && i+1 != HEIGHT_MAP){//checks tile below
				temp.push_back(matNodes[i+1][j]);
			}
			if(map.getTilePassable(i-1,j) && i-1 != -1){//checks tile above
				temp.push_back(matNodes[i-1][j]);
			}
			if(map.getTilePassable(i,j+1) && j+1 != WIDTH_MAP){//checks tile to right
				temp.push_back(matNodes[i][j+1]);
			}
			if(map.getTilePassable(i,j-1) && j-1 != -1){//checks tile below
				temp.push_back(matNodes[i][j-1]);
			}

			this->nodeMap[nIndex] = temp;

			nIndex++;
		}
	}

	for(int intev : this->nodeMap[62]){
		//std::cout<<intev<<" ";
	}
	std::cout<<std::endl;
}
		
void TankAI::searchPath(){

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

				if (nCurrent == this->nTarget) {
					// once bPathfound is no longer false, the loop should end.
					this->bPathFound = true;
				}


        		for (int nAdj_vertex : this->nodeMap[nCurrent]) { //check mapData for connections to push to the queue of options and insert to the sets cleared.

            		if (setCleared.find(nAdj_vertex) == setCleared.end()) {
						
                		qOption.push(nAdj_vertex);
                		setCleared.insert(nAdj_vertex);
						this->refData[nAdj_vertex] = nCurrent;

            		}
        		}
    		}

}

char TankAI::logPath(){

    int nCurrentPos = 0;

	nCurrentPos = this->nTarget;
	this->vecRoute.clear();

	while (nCurrentPos != this->nStart) { //chart and insert the values into the route vector

		this->vecRoute.push_back(nCurrentPos);
		nCurrentPos = this->refData[nCurrentPos];

	}

	this->vecRoute.push_back(this->nStart); //finally push back the target position itself

	std::cout<<this->vecRoute.size()<<std::endl;
	std::cout<<std::endl;
	
	// Logs the path to the target

	for (int i = this->vecRoute.size() - 1; i > 0; i--) {

			if (this->vecRoute[i] == this->vecRoute[i - 1] + this->nColumns) { // NORTH

				return 'N';
			}

			if (this->vecRoute[i] == this->vecRoute[i - 1] + this->nColumns) {	// SOUTH

				return 'S';
			}

			if (this->vecRoute[i] == this->vecRoute[i - 1] + 1) {	// WEST

				return 'W';
			}

			if (this->vecRoute[i] == this->vecRoute[i - 1] - 1) {	// EAST

				return 'E';
			}

			
	}

	return ' ';	
}

void models::TankAI::setSelfX(int x)
{
	this->selfX = x;
}

void models::TankAI::setSelfY(int y)
{
	this->selfY = y;
}
