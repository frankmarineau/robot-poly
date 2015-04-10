#include "Sonar.h"


     
Sonar::Sonar();
{
  	Utility::ajustementTimer3(void);
} 
  
inline uint8_t Sonar::getDistance()
{
	return distance_;
}

inline void Sonar::setDistance(uint8_t d) 
{
	distance_ =d;
}

uint8_t Sonar::readDistance()
{

}
