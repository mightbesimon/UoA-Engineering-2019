% task 3 lab 3
% recalls NumberOfRealRootsForQuadratic function
% Simon Shan

clear;
clc;

% input coefficients
a = input('enter the coefficient a = ');
b = input('enter the coefficient b = ');
c = input('enter the coefficient c = ');

disp(['the equation has ' num2str(NumberOfRealRootsForQuadratic(a , b , c)) ' real roots']);