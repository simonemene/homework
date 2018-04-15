#include "ros/ros.h"
#include "std_msgs/Char.h"
#include "std_msgs/String.h"
#include <string>
#include <signal.h>




std::string comando = "";



void chatterCallback(const std_msgs::String::ConstPtr& msg){

	comando = msg->data;
	

}

std::string inserimentoValore(){
	std::string inserimento;
	std::cout << "'a' : stampa tutto il messaggio " << std::endl;
	std::cout << "'n' : stampa il nome" << std::endl;
	std::cout << "'e' : stampa l'età " << std::endl;
	std::cout << "'c' : stampa il corso di laurea" << std::endl;
	std::cout << "'u' : exit" << std::endl;

	std::cout << "inserisci una lettera" << std::endl;
	std::cin >> inserimento;
	

	
	return inserimento;
}



	

int main( int argc, char **argv) {

	ros::init(argc,argv,"nodo2");

	
	ros::NodeHandle nn;

	
	ros::Subscriber sub = nn.subscribe("menu",1000,chatterCallback);
	
	

	ros::Publisher nodo2 = nn.advertise<std_msgs::String>("comando",1000);

	

	

	

	
	while(ros::ok()){

	

		std_msgs::String messaggio;
		std::stringstream valore;

		valore << inserimentoValore();



	
		messaggio.data = valore.str();

		nodo2.publish(messaggio);


	

		ros::spinOnce();

		

		comando = "";		

		while(comando == ""){

			ros::spinOnce();
			
		}

		if(comando == "fine"){
			ros::shutdown();
		}

		

	
		
	}

	




	return 0;
}
	

	






