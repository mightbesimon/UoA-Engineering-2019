% task5 lab2
% recalling funciton Spring
% Simon Shan

clear;
clc;

% input values
f = input('force = ');
k = input('spring constant = ');

% recall function
[x, ep] = Spring(f, k);

disp([x, ep]);