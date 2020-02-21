% task 3 lab 6
% plot the analytic solution
%
% given     
%   -       mass = 1000
%   -   vInitial = 5
%   - airResCoef = 500
%
% plot velocity over time
% over the time interval 0 <= t <= 10
%
% simon shan



% housekeeping %
close all ;
fclose all;
clear; clc;


% solve numerically
v0 = 5;
timeInterval = [0 10];


[t , v] = ode45(@SledAcceleration , timeInterval , v0);

% plot %
plot   (t , v , '-o');
title  ('numerical solution');
xlabel ('time (s)');
ylabel ('velocity (m/s)');


% function %
function dvdt = SledAcceleration (~ , v)

mass = 1000;
c    = 500 ;
dvdt = -c * v / mass;

end