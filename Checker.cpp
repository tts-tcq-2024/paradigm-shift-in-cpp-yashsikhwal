#include <assert.h>
#include <iostream>
using namespace std;

// Function to verify minimum and maximum temperature
bool checkTemperature(float temperature)
{
  if(temperature < 0 || temperature > 45) 
  {
    cout << "Temperature out of range!\n";
    return false;
  }
  return true; 
}

// Function to verify minimum and maximum SOC value
bool checkSoc(float soc)
{
  if(soc < 20 || soc > 80) 
  {
    cout << "State of Charge out of range!\n";
    return false;
  }
  return true;
}

// Function to verify maximum charge rate
bool checkChargeRate(float chargeRate)
{
  if(chargeRate > 0.8) 
  {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
  return checkTemperature(temperature) && checkSoc(soc) && checkChargeRate(chargeRate);
}

int main() 
{
  // Temperature < 0, rest optimal
  assert(batteryIsOk(-0.1, 70, 0.1) == false);
  // Temperature > 45, rest optimal
  assert(batteryIsOk(45.1, 70, 0.3) == false);
  // SOC < 20, rest optimal
  assert(batteryIsOk(25, 19, 0.4) == false);
  // SOC > 80, rest optimal
  assert(batteryIsOk(26, 85, 0.5) == false);
  // Charge Rate > 0.8, rest optimal
  assert(batteryIsOk(30, 60, 0.81) == false);
  // All optimal values
  assert(batteryIsOk(30, 60, 0.7) == true);
}
