% task 2 lab 6
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


% solve analytically
mass = 1000;
v0 = 5;
c = 500;
t = linspace(0 , 10 , 100);

v = v0 * exp(-c * t / mass);


% plot %
plot   (t , v , '-o');
title  ('numerical solution');
xlabel ('time (s)');
ylabel ('velocity (m/s)');




