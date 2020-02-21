function m = ImperialToMetric(ft,in)
% IMPERIALTOMETRIC converts an imperial measurement (in feet and inches)
% to a metric measurement (in metres)
% INPUTS: ft = number of feet
%         in = number of inches
% OUTPUT: m  = measurement in metres

% Calculate the total number of inches
totalInches = ft * 12 + in;

% Calculate the number of metres
m = totalInches * 2.54 / 100;

return