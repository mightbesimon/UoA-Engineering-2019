%calculates lab1 task5 resistance
%Simon Shan

%input values
R  = 0;
R1 = input('resistance of R1 = ');
R2 = input('resistance of R2 = ');
R3 = input('resistance of R3 = ');
V  = input('voltage = ');

%calculations
R = 1 / (1 / R1 + 1 / R2);
R = R + R3;
I = V/R; 
