8% task 1 lab 4
% produces two sets electrocardiograph
%
% set 1
%   - unprocessed signal (GREEN)
%   - smoothed signal after 100 passes (DASHED RED)
%
% set 2
%   - unprocessed signal (SOLID BLACK)
%   - smoothed signal after 1 pass
%   - smoothed signal after 100 passes
%
% simon shan

% housekeeping %
close all;
clear;
clc;
load('signal.mat');



% -------------------- set 1 -------------------- %

% unprocessed signal (GREEN) %
plot   (t , y , 'GREEN');
title  ('electrocardiograph set 1');
xlabel ('time (s)');
ylabel ('signal strength');


% processed signal (DASHED RED) %

for i = 1 : 100
    
    y = smooth(y);
    
end


hold on;
plot (t , y , 'RED--');
legend('unprocessed signal' , 'smoothed signal (100 times)');



% -------------------- set 2 -------------------- %

load('signal.mat');

% unprocessed signal (BLACK) %
figure();
subplot (1,3,1);
plot    (t , y , 'BLACK');
title   ('unprocessed signal');
xlabel  ('time (s)');
ylabel  ('signal strength');

% once processed signal (BLACK) %
y = smooth(y);

subplot (1,3,2);
plot    (t , y , 'BLACK');
title   ('processed signal (1 pass)');
xlabel  ('time (s)');
ylabel  ('signal strength');

% 100 times processed signal (BLACK) %

for i = 1 : 100
    
    y = smooth(y);
    
end

subplot (1,3,3);
plot    (t , y , 'BLACK');
title   ('processed signal (100 passes)');
xlabel  ('time (s)');
ylabel  ('signal strength');






% -------------------- smoothing function -------------------- %

function yProcessed = smooth(y)

yProcessed = y;

for i = 2 : 999
    
    oldPoints = [y(i-1) , y(i) , y(i+1)];
    newPoint = ThreePointSmooth(oldPoints);
    yProcessed(i) = newPoint;
    
end

end
