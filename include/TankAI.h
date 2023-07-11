#ifndef MODELS_TANKAI_H
#define MODELS_TANKAI_H

#include "unordered_map"
#include "vector"
#include "queue"
#include "unordered_set"
#include "../include/Map.h"
#include "../include/Tank.h"


namespace models{

    class TankAI {

        private:

        std::unordered_map<int, std::vector<int>> mapData; //representing the graph to be used
		std::unordered_map<int, int> refData; //used as the "parent" node reference point
		std::vector<int> vecRoute; //vector that will be used as a reference point to write onto a file that indicates the route taken by the entity to achieve the target
		std::vector <std::vector<int>> vecTemp; /*temporary vector to store the map values for edge creation, this was originally not an attribute, but I found it was creating 
		                              a whole host of errors otherwise....*/
		int selfX;
        int selfY;
        int nRows;
		int nColumns;
		int nStart;
		int nTarget;
		bool bPathFound;


		/*Constructors / function prototypes (I normally dont do function prototypes in this section but since hpp is not allowed I need to jam it here...)*/

		public:

		TankAI(int tankX, int tankY);

        public:

        void logEdges(int nVertex, int nAdj_vertex);

		void logMapEdges(Map &map, Tank &player);

		void searchPath();

		char logPath();

        int getSelfX();
        int getSelfY();

        void setSelfX(int x);
        void setSelfY(int y);	

    };
}



#endif