% calculate the numerical solution of the ODE
% dydt = cos(omega * t);

% set up an array containing the start time and finish time
% we will calculate solution values for this time range
% we only need to specify TWO values (the start and finish)
timeInterval = [0 1];

% our initial condition is y(0)=0
yinit = 0;

% solve our ODE, the solver expects three arguments in the
% the following order
% - the name of the derivative function (in quotes)
% - the time interval to solve for (a two element row vector)
% - the value at the start time
[t,y] = ode45('SinusoidDerivative', timeInterval, yinit);
plot(t,y)