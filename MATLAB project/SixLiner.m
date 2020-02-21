function [medianImage , maxImage] = SixLiner(dirName , fileType)
% SixLiner: does the matlab project in six lines of code
%
% inputs  :    dirName = directory of the images
%			  fileType = file extension type of the images
% outputs :medianImage = image background
%			  maxImage = images combined on background
%
% by simon shan



% ---------------- 6 lines ---------------- %

dirFiles = dir(dirName + "/*." + fileType);
images   = cellfun(@imread , dirName+ "/" + {dirFiles.name}, 'UniformOutput', false);
% remove action %
medianImage = median(cat(4 , images{:}) , 4);
% action shot %
[~,index]   = max(sum((double(cat(4 , images{:})) - double(medianImage)) .^  2 , 3) , [] , 4);
layerIndex(1 , 1 , 1 , 1:length(images)) = 1 : length(images);
maxImage    = uint8(sum(double(cat(4 , images{:})) .* (index == layerIndex) , 4));

% ---------------- 6 lines ---------------- %


end