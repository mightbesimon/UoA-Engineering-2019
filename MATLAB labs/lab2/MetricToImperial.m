function [ft,in] = MetricToImperial(m)
% This function converts a metric measurement (in metres)
% to an imperial measurement (in feet and inches)
% Input: m = measurement in metres
% Outputs: ft = number of feet
%          in = number of inches

% Calculate the total number of cms
cm = m * 100;

% Calculate the total number of inches
totalInches = cm/2.54;

% Calculate the total number of feet, ignoring the value
% after the decimal point
% the floor command rounds down to the nearest whole number
ft = floor(totalInches/12);

% Find the remaining number of inches
in = totalInches - 12*ft;

return