function [realRoots] = NumberOfRealRootsForQuadratic(a , b , c)
% this function returns the number of real roots of a quadratic equation
% Input:  a = coefficient of x ^ 2
%           b = coefficient of x
%           c = coefficient of 1
% Output: nRealRoots = number of real roots
% Simon Shan

% calculate the discriminant
discriminant = b ^ 2 - 4 * a * c;

% determine roots
if discriminant > 0
    
    realRoots = 2;
    
elseif discriminant == 0
    
    realRoots = 1;
    
else
    
    realRoots = 0;
    
end

%realRoots = (discriminant == 0) + 2 * (discriminant > 0);
%realRoots = sign(discriminant) + 1;

return