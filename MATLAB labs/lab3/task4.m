% task 4 lab 3
% randomly predicts how many shuttle flights before losing a shuttle
% Simon Shan

clear;
clc;

% initial values
numberOfFlights = 0;
%chancesOfFailure = 1;

% simulation
%while chancesOfFailure >= 0.01
while true
    
    chancesOfFailure = rand();
    if chancesOfFailure < 0.01 , break , end

    numberOfFlights = numberOfFlights + 1;
    
end

disp(['you completed ' num2str(numberOfFlights) ' successful missions before losing a shuttle']);
