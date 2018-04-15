#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Char.h"
#include <string>
#include <cstring>
#include <signal.h>



std::string dato1;


std::string comando1;




void chatterCallback(const std_msgs::String::ConstPtr& msg) {

	
	
	comando1 = msg->data;
	
	
	
	

	

	
}


void chatterCallback1(const std_msgs::String::ConstPtr& msg1){

	
	dato1 = msg1->data;
	
	

}



	

	


int main(int argc, char **argv) {

	ros::init(argc,argv,"nodo3");

	ros::NodeHandle n;

	ros::Subscriber sub1 = n.subscribe("dati",1000,chatterCallback1);

	ros::Subscriber sub = n.subscribe("comando",1000,chatterCallback);
		
	ros::Publisher pub = n.advertise<std_msgs::String>("menu",1000);


	
	while(ros::ok()){

	
		while(dato1 == ""){
			ros::spinOnce();
		}
	
	
		
		
		
	
		while(comando1 == ""){
			ros::spinOnce();
		}
	
	
		int dimensione = dato1.length();
		std::string name;
		std::string age;
		std::string graduation;
		std::string completa = dato1;
		
		

		std::size_t posizionePrimoSpazio = dato1.find(" ");
		name = dato1.substr(0,posizionePrimoSpazio);
		
		dato1 = dato1.substr(posizionePrimoSpazio+1,dato1.length());
		
		std::size_t posizioneSecondoSpazio = dato1.find(" ");
		age = dato1.substr(0,posizioneSecondoSpazio);
		
		dato1 = dato1.substr(posizioneSecondoSpazio+1,dato1.length());
		graduation = dato1.substr(0,dato1.length());

		std_msgs::String messaggio;
		std::stringstream ms;
	
		ros::Rate loop(10);

	
		if(comando1 == "a") {
			ROS_INFO("STRINGA : %s",completa.c_str());
		}else if(comando1 == "n"){
			ROS_INFO("NOME : %s",name.c_str());
		}else if(comando1 == "e"){
			ROS_INFO("ANNI : %s",age.c_str());
		}else if(comando1 == "c"){
			ROS_INFO("CORSO : %s",graduation.c_str());
		}else if(comando1 =="u"){
			ms << "fine";
			messaggio.data = ms.str();
			pub.publish(messaggio);
			
			ros::spinOnce();
			loop.sleep();
			
			ros::shutdown();
			
		}else{
			ROS_INFO("lettera errata");
		}

		

		
		dato1 = "";
		comando1 = "";
		
	

		
			
	
		ms << "menù";
		

		messaggio.data = ms.str();
		
		pub.publish(messaggio);

		
		loop.sleep();
		ros::spinOnce();
		
	
	

	}

	
	

	return 0;
}

	
