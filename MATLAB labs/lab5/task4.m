% task 4 lab 5
% read volume and temperature from text file
% to calculate the pressure of the gases



% housekeeping %
close all;
fclose all;
clear; clc;



% load gasData.txt into data
fopen('gasData.txt');
fgetl(3);
gasData = fscanf(3 , '%f');
fclose all;


% contruct volume and temp and calculate pressure
volume      = gasData (1 : 2 : 1999);
temperature = gasData (2 : 2 : 2000);
pressure    = 2 * 8.314 * temperature ./ volume;


% write pressureData.txt
fopen('pressureData.txt' , 'w');
fprintf (3 , 'Pressure (Pa)\n');
fprintf (3 , '%f\n' , pressure(1:1000));
fclose all;
