#ifndef ROUTE_PLANNER_H
#define ROUTE_PLANNER_H

#include <iostream>
#include <vector>
#include <string>
#include "route_model.h"


class RoutePlanner {
  public:
    RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y);
    // Add public variables or methods declarations here.
		float GetDistance();
		void AStarSearch();
  private:
		std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node*);
    RouteModel& m_Model;
  	RouteModel::Node* start_node;
  	RouteModel::Node* end_node;
  	float distance;
  	float CalculateHValue(RouteModel::Node*);
		std::vector<RouteModel::Node*> open_list;
    RouteModel::Node* NextNode();
		void AddNeighbors(RouteModel::Node*);
};

#endif