% The BlueCount script will scan a user specified row of an image
% and determine the percentage of pixels in that row which are blue
% It uses your PixelIsBlue function to count the number of pixels
% so make sure you have written and tested that function before trying 
% this task.
%
% Unfortunately this scripts has BUGS!!
% Here is what it SHOULD display if reading image logo.jpg
% and entering row 1, 50, 95 and 100 respectively.
%
% Percentage of blue in row 1 is 0%
% Percentage of blue in row 50 is 17.3469%
% Percentage of blue in row 95 is 60.7143%
% Percentage of blue in row 100 is 90.3061%
% 
% Note that debugging is often easier if you try running your code over a
% much smaller data set, so try using the test.jpg image available on cecil 
% as it only has 3 rows and 4 columns. You should be able to calculate the 
% expected results for test.jpg by hand and then use the debugger to step 
% through the code and see whether it is doing what you expect or not.
% Author: Mr Blu Ray

clear

% ask the user to specify the name of a jpg file
fileName = input('Please enter the name of a jpg file to read in (e.g. logo.jpg):','s');
rowNumber = input('Please enter the row number to scan:');
% Import the image data into an array
imageData = imread(fileName, 'JPG');

% Plot the original image
figure(1)
image(imageData);
axis equal


% determine dimensions of image data
[rows, cols, colours] = size(imageData);
% Check each pixel in the row, one at a time, to see if it is blue.

count = 0;

for i = 1:cols
    
    % extract colour values for current pixel from specfied rowNumber
    r = imageData(rowNumber, i, 1);
    g = imageData(rowNumber, i, 2);
    b = imageData(rowNumber, i, 3);
    if PixelIsBlue(r,g,b)
        count = count + 1;
    end
end
bluePercent = count/cols*100;

disp(['Percentage of blue in row ' num2str(rowNumber) ' is ' num2str(bluePercent) '%']);

