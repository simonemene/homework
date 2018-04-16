#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

std::string comando = "";





void chatterCallback(const std_msgs::String::ConstPtr& msg){

	comando = msg->data;
	
	

}



int main(int argc, char **argv) {


	ros::init(argc,argv,"nodo1");
	
	ros::NodeHandle ns;


	ros::Publisher nodo = ns.advertise<std_msgs::String>("dati",1000);

	ros::Subscriber sub = ns.subscribe("comando",1000,chatterCallback);

	
	ros::Rate loop_rate(1);

	while( ros::ok() ) {
		

		std_msgs::String msg;
		std::stringstream nome;
		nome << "Marco_Rossi 23 Informatica";
		msg.data = nome.str();

		nodo.publish(msg);

		loop_rate.sleep();
		

		ros::spinOnce();
		
		if(comando == "u"){
			ros::shutdown();
			
		}

		

		
		
		
	}

	

	

	

	

	return 0;
}
		
		

	

	
