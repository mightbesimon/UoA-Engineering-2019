function echo = PixelIsBlue (r , g , b)
% PIXELISBLUE checks if a set of rgb values is considered blue
%
% INPUTS: r    = amount of RED
%         g    = amount of GREEN
%         b    = amount of BLUE
% OUTPUT: echo = if the pixel is blue (1 for true, 0 for false)


echo = 0;

if (r < 128) && (g < 128) && (b >= 128)
    
    echo = 1;
    
end

return