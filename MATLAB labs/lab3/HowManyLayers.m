function layers = HowManyLayers(Tc,Ws)
% HowManyLayers should determine how many layers of clothing to wear based 
% on two inputs:
% Tc, the temperature (measured in degrees celsius)
% Ws, the wind speed (measured in kilometers per hour)
% UNFORTUNATELY IT IS BUGGY.
%
% Here is how it SHOULD work.
% The number of layers assumes a layer is approximately 2mm thick and
% is calculated using Robert Steadman’s Clothing index (1971),
% which provides a table so that you can can look up the required
% thickness based on temperature and wind speed.
% Steadman's table only covers temperatures within the range -4 and 10
% degrees (inclusive) and windspeeds 50 km/h or less
% If the function is called with values outside the valid range 
% an error message will display and a value of -1 will be returned
%
% Here are a few examples of calling the function
% HowManyLayers(20,10)
%   will return -1 and display an error message,
%   as the temperature is above 10 degrees
% HowManyLayers(5,60)
%   will return -1 and display an error message as the wind is above 50km/h
% HowManyLayers(10,5)
%   will return 1 (i.e. 1 layer is required at 10 degrees with a 5 km/h wind
% HowManyLayers(5,20)
%   will return 3 (i.e. 3 layers are required at 5 degrees with 20 km/h wind
%
% TO DEBUG, read through the code to get an idea of what it should do.  
% Then try calling the function with the command line with a range
% of values to see if it works as expected.
% The examples given above are an excellent place to start
% If calling the function generates any errors then read the error
% message and click on it to be taken to the line that has a problem, so 
% that you can fix the probem.
%
% If the code runs but does not do what you expect, try rereading through
% the chunk of code you think might be causing the probem.  
% If you still can't spot any problems after reading through 
% the code, then place a break point at the start of conditional you think
% is causing issues.
% You can then use debugger to step through the code line by line
% so that you can see what the code does and verify your conditionals
% are behaving as expected.
%
% Remember that you can easily check the current value of a variable by
% hovering your mouse over a variable name or looking in the workspace 
%
% Author: Peter Bier

% set up clothing array for Steadman's clothing index
% each row corresponds to a windspeed
% (row 1 is for 0km/h, row 2 is for 5km/h, row 3 is for 10km/h etc).
% each column corresponds to a temperature (column 1 is for 10 degrees,
% column 2 is for 9 degrees, column 3 is for 8 degrees etc).
clothingLayers =[
    1 1 1 1 1 1 2 2 2 2 3 3 3 4 5;
    1 1 1 1 1 1 2 2 2 2 3 3 3 4 5;
    1 1 1 1 2 2 2 2 3 3 3 3 4 5 6;
    1 1 2 2 2 2 3 3 3 3 4 4 4 5 6;
    1 2 2 2 2 3 3 3 3 4 4 4 5 6 7;
    2 2 2 2 3 3 3 3 4 4 4 5 5 6 7;
    2 2 2 2 3 3 3 4 4 4 5 5 5 6 8;
    2 2 2 3 3 3 3 4 4 4 5 5 5 7 9;
    2 2 3 3 3 3 4 4 4 5 5 5 6 7 9;
    2 2 3 3 3 3 4 4 4 5 5 5 6 7 10;
    2 2 3 3 3 4 4 4 5 5 5 6 6 8 10];

% check if wind speed and temperature are within required range
if (0 <= Ws) && (Ws <=  50) && (-4 <= Tc) && (Tc <= 10)
    % determine which row to use, by dividing the wind speed by 5 and
    % rounding to the nearest whole number and adding 1 
    row = round(Ws/5) + 1;
    % determine which column to use by subtracting the rounded temperature from 11
    % e.g. 10 degrees becomes 11-10 = 1 (column 1)
    % -4 degrees becomes 11- -4=15 (column 15)
    column = 11 - round(Tc);
    % look up layers
    layers = clothingLayers(row,column);
else
    disp('Error using HowManyLayers:');
    disp('Your temperature must be within the range -4 and 10 degrees C');
    disp('and your wind speed must be 50 km/h or less.');
    layers = -1;
end


end