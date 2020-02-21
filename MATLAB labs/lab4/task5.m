% task 5 lab 4
% replace all non-blue pixels with white
% simon shan



% housekeeping %
close all;
clear; clc;


% input image file
fileName  = input ('file name = ' , 's');
imageData = imread (fileName, "jpg");

image(imageData);
axis equal;



% search and replace
[x , y , z] = size(imageData);
for i = 1 : x
    
    
    for j = 1 : y
        
        
        r = imageData(i , j , 1);
        g = imageData(i , j , 2);
        b = imageData(i , j , 3);
        
        if ~PixelIsBlue(r , g , b)
            
            imageData(i , j , [1,2,3]) = 255;
            
        end
        
    end
    
end



% filtered image
figure();
image(imageData);
axis equal;

