% task 5 lab 3
% randomly predicts how many shuttle flights before losing a shuttle
% Simon Shan

clear;
clc;

% input number of simulations
prompt = 'how many simulations would you like to run, boss? ';
numberOfSimulations = input(prompt);

successfulMissions = zeros(1 , numberOfSimulations);

% loop
for i = 1 : numberOfSimulations
    
    % initial values
    %numberOfFlights = 0;
    chancesOfFailure = 1;

    while chancesOfFailure >= 0.01
    
        %numberOfFlights = numberOfFlights + 1;
        successfulMissions(i) = successfulMissions(i) + 1;
        chancesOfFailure = rand();
    
    end
    
    %successfulMissions(i) = numberOfFlights;
    
end

histogram(successfulMissions);