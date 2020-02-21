% task 1 lab 6
% - part i
%   solve matrix equations
%   find the current
% - part ii
%   how much voltage increase before wire melts
%   (wire melts when 5A flows through any wire)
% simon shan



% housekeeping %
close all ;
fclose all;
clear; clc;




% -------------------- part i -------------------- %

% contruct matrices
A = [
     1 -1  0  0  0  ;
     0  1  1 -1  0  ;
     0  0 -1  1 -1  ;
    -1  0  0  0  1  ;
     0  3  0  4  3  ;
     0  3  0  0  3  ;
     0  0  0  4  0  ];

b = [0 ; 0 ; 0 ; 0 ; 10 ; 6 ; 4];

i = A \ b;

%PART1answer = i;
disp (i);



% -------------------- part ii -------------------- %

% 
V1 = 10;
while i(1 : 5 , 1) <= 5
    
    V1 = V1 + 0.1;
    
    b = [0 ; 0 ; 0 ; 0 ; V1 ; V1 - 4 ; 4];
    i = A \ b;
    
    %if i(1 : 5) > 5, break, end
    
end

disp (['the max voltage that can be applied is ' num2str(V1 - 0.1) ' volts']);