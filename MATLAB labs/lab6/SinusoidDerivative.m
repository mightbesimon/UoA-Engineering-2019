function [dydt] = SinusoidDerivative(t,y)
% calculate the derivative dy/dt for the equation
% dy/dt = cos(omega * t)
% inputs: t, the independent variable representing time
% y, the dependent variable representing displacement
% output: dydt, the derivative of y with respect to t

% omega is the angular frequency
omega = 2 * pi;
dydt = cos(omega * t);

return