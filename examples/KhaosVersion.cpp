#include <Khaos/KhaosVersion.h>
#include <iostream>

int main()
{
  std::cout<<"Khaos version : "<<GET_VERSION_MAJOR(Khaos)<<"."<<GET_VERSION_MINOR(Khaos)<<"."<<GET_VERSION_PATCH(Khaos)<<"."<<GET_VERSION_TWEAK(Khaos)<<std::endl;
}