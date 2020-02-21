%calculates lab1 task4 resistance
%Simon Shan

%initial values
R  = 0;
R1 = 5;
R2 = 10;
R3 = 2;
V  = 6;

%calculations
R = 1 / (1 / R1 + 1 / R2);
R = R + R3;
I = V/R; 
