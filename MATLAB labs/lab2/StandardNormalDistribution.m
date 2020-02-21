function [sx] = StandardNormalDistribution(x)
% exam practice 1 lab 2
% calculates s(x) from x
% using the formula s(x) = 1 / (sqrt(2 * pi)) * exp ( -0.5 * x ^ 2)
% Simon Shan

% input value
x = input('input value x = ');

sx = 1 / (sqrt(2 * pi)) * exp ( -0.5 * x ^ 2);

return