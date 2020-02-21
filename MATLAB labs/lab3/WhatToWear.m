% This script should display to the user the "feels like" temperature
% and give them advice on what clothing to wear on COLD days 
% (i.e. when the temperature is 10 degrees or less) but it is BUGGY!
%
% Here is what it SHOULD DO:
% The script will ask the user to enter the temperature (in degrees C),
% the average wind speed (in km/h) and the expected rainfall (in mm).
% If a temperature of 10 degrees or below is entered then the script 
% displays the "feels like" temperature and advises on what 
% clothing to wear. The "feels like" temeprature may be colder than the 
% actual temperature, as when it is windy the "wind chill" factor can 
% make it feel a lot colder.
% If a temperature above 10 degrees is entered, an error message is generated.
%
% The wind chill formula used is that published by the Northern American 
% Joint Action Group for Thermal indices in 2001. 
% This formula is only valid for temperatures 10 degrees celsius or lower and 
% for wind speeds of 5km/h or greater
% If you are curious about the formulae used, you may like to read the 
% following blog post:https://blog.metservice.com/FeelsLikeTemp

% TO DEBUG, read through the code to get an idea of what it should do.  
% Note that this code uses the HowManyLayers function.  Before doing
% anything else go and make sure that function works as expected.
% Once you are happy that HowManyLayers is debugged and working, try running
% this script.  If it generates any errors then read the error
% message and click on it to be taken to the line that has a problem, so 
% that you can fix the probem.
%
% If your code runs but does not do what you expect, try rereading through
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

% get forecast data from user
disp('Please enter the relevant forecast data (available from www.metservice.com)');
Tc = input('Temperature (in celsius):');
Ws = input('Wind speed (in km per hour):');
rainfall = input('Rainfall (in mm):');

% check temperature is within valid range to use formulae 
if Tc > 10
    disp('Please note that this script is only to be used when the temperature is 10 degrees or below.');
else
    % temperature is 10 degress or lower, so formuale are valid
    
    % calculate "feels like" temperature (wind chill temperature)
    if Ws >= 5
        % formulae only valid if wind speed is greater that or equal to 5 km/h
        feelsLike = 13.12 + 0.6215 * Tc - 11.37 * Ws^0.16 + 0.3965 * Tc * Ws^0.16;
    else
        feelsLike = Tc;
    end
    %
    % determine how many layers to wear
    layers = HowManyLayers(Tc,Ws);
    
    disp(['It feels like ' num2str(round(feelsLike)) ' degrees celsius.']);
    disp (['You should wear ' num2str(layers) ' layer(s) of clothing.']);
    % determine if a rain coat is needed
    if rainfall == 0
        disp('You do not need a raincoat.');
    else
        disp('Make sure one of your layers is a raincoat.')
    end
end
