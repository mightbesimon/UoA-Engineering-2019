% housekeeping %
clear; clc;


% function call %
[medianImage, maxImage] = SixLiner('lunar', 'jpg');


% output %
image(medianImage);
axis equal
figure
image(maxImage);
axis equal
