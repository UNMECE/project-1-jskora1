#include <iostream>
#include <cmath>


struct _capacitor
{
double *time;
double *voltage;
double *current;
double C;
};
typedef struct _capacitor Capacitor;


double I_c (double C, double dV_dt) {

	return C * dV_dt;
}

int main () {

double i0 = 1e-2;
double v0 =10.0;
double C = 100e-12;
double R= 1000;
double t_f = 5e-6;
double delta_t = 1e-10;
int t_steps = t_f / delta_t;
double t;

double dV_dt = i0 / C;

Capacitor cap = { NULL, NULL, NULL, C };

// I_c Circuit //

std::cout << "\nConstant Current Source Power Supply\n" << std::endl;

cap.time = new double [t_steps];
cap.voltage = new double [t_steps];
cap.current = new double [t_steps];

cap.time[0] = 0.0;
cap.voltage[0] = 0.0;
cap.current[0] = i0;
for (int i = 0; i < t_steps; ++i) {
	cap.time[i] = cap.time[i - 1] + delta_t;
	cap.voltage[i] = cap.voltage[i - 1] + dV_dt * delta_t;
	cap.current[i] = i0;



if (i % 200 == 0) {	
std::cout << "Time " <<cap.time[i] << " s   Voltage " << cap.voltage[i] << " V   Current " << cap.current[i] << " A\n";
  }
} 

delete[] cap.time;
delete[] cap.voltage;
delete[] cap.current;

// RC Circuit //

std::cout << "\nConstant Voltage Source Power Supply\n" << std::endl;

cap.time = new double [t_steps];
cap.voltage = new double [t_steps];
cap.current = new double [t_steps];

cap.time[0] = 0.0;
cap.voltage[0] = 0.0;
cap.current[0] = v0 / R;



for (int i = 0; i < t_steps; ++i) {

	cap.time[i] = cap.time[i - 1] + delta_t;
	double dV_dt = (v0 - cap.voltage[i-1]) / (R * C);
	cap.voltage[i] = cap.voltage[i - 1] + dV_dt * delta_t;
	cap.current[i] = (v0 - cap.voltage[i]) / R;



if (i % 200 == 0) {	
std::cout << "Time " <<cap.time[i] << " s   Voltage " << cap.voltage[i] << " V   Current " << cap.current[i] << " A\n";
  }
} 

delete[] cap.time;
delete[] cap.voltage;
delete[] cap.current;


  return 0;
}


