% housekeeping %
clear; clc;
dirName = 'lunar';
fileType = 'jpg';




% 6 lines of actual code


% ---------------- 6 lines ---------------- %

dirFiles  = dir(dirName + "/*." + fileType);				% get files in the directory
images = cellfun(@imread , dirName+ "/" + {dirFiles.name}, 'UniformOutput', false);
															% reads the images
imageStack = cat(4 , images{:});							% stacks the images
medianImage = median(imageStack , 4);						% median rgb image
[~,index]= max(sum((double(imageStack) - double(medianImage)) .^  2 , 3) , [] , 4);	
															% get set number of the odd pixel
maxImage=uint8(sum(double(imageStack) .* (index == reshape(1:length(images) , 1 , 1 , 1 , [])) , 4));
															% puts odd ones out in max rgb image

% ---------------- 6 lines ---------------- %




% output %
image(medianImage);
axis equal
figure
image(maxImage);
axis equal
