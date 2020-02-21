% task 2 lab 4
% draws surfaces using two methods
% simon shan



% housekeeping %
close all;
clear; clc;



% -------------------- method 1 -------------------- %

% define the domain
x = linspace (-1 , 1 , 10);
y = linspace (-2 , 2 , 10);
X = zeros (10 , 10);
Y = zeros (10 , 10);

% create grid
for i = 1 : 10
    
    for j = 1 : 10
        
        X (i , j) = x (j);
        Y (j , i) = y (j);
        
    end
    
end

Z = (X .^ 2) .* Y .* (Y - 1).* (Y + 1);


% plotting %
surf   (X , Y , Z);
xlabel ('x');
ylabel ('y');
zlabel ('height');
title  ('f (x , y)');




% -------------------- method 2 -------------------- %
figure();


% domain
x = linspace (-1 , 1 , 100);
y = linspace (-2 , 2 , 100);
X = zeros (10 , 10);
Y = zeros (10 , 10);

% grid
[X , Y] = meshgrid (x , y);
Z = (X .^ 2) .* Y .* (Y - 1).* (Y + 1);


% plotting %
surf   (X , Y , Z);
xlabel ('x');
ylabel ('y');
zlabel ('height');
title  ('f (x , y)');

