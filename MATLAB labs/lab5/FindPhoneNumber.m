% This script prompts a user for a name (or part of a name) and then 
% searches through a list of 13 dwarves to see which ones match (ignoring
% case).  For any that match, their phone number is displayed.  
% If there are no matches then a message is displayed to indicate no 
% matches were found. Unforunately this script is BUGGY!
% Author: Bilbo Baggins
%
% Here is a description of how it SHOULD work
% Entering the string Thorin should bring up Thorin's phone number, 
% i.e. it should display the line:
%  Name: Thorin   Number: 1777
% Entering the string fili (note lowercase f) should bring up Fili's 
% number. It should display the line:
%  Name: Fili   Number: 2777 
% Entering the string ILI (note capitals) should bring up Fili and Kili's 
% number (since both contain ili).  It should display the lines:
%  Name: Fili   Number: 2777 
%  Name: Kili   Number: 3777
% Entering the string Oin should bring up Oin and Gloin's number (since 
% both contain oin).  It should display the lines: 
%  Name: Oin   Number: 6777 
%  Name: Gloin   Number: 7777
% Entering the name Bilbo should display the line:
%  Did not find a match for Bilbo
% since that name is not in the phonebook

% set up list of names
phoneBookNames = {'Thorin','Fili','Kili','Balin','Dwalin','Oin','Gloin','Ori','Dori','Nori','Bifur','Bofur','Bombur'};

% set up list of phone numbers 
phoneBookNumber = [1777 2777 3777 4777 5777 6777 7777 8777 9777 1077 1177 1277 1377];
disp('Who do you want to find a phone number for?');
name = input('Please enter a name or part of a name:' , 's');

peopleFound = 0;

% scan through phone book and print out any matches
for i=1:length(phoneBookNames)
    currentName = phoneBookNames{i}; % get current name from cell array
       if contains(currentName,name,'IgnoreCase',true)
           disp(['Name: ' currentName '   Number: ' num2str(phoneBookNumber(i))]);
           peopleFound = peopleFound + 1;
       end
end

% if we didn't find anyway display a message to that effect.
if peopleFound == 0
    disp(['Did not find a match for ' name]);
end
