function [compression, pEnergy] = Spring(force, sConstant)
% this function calculates the compression and potential energy of a spring
% from the force and spring constant of the spring
% Input:  force = force the spring experiences (in Newtons)
%           sConstant = the spring constant (in N/m)
% Output: compression = compression in metres
%           pEnergy = the potential energy in the spring (Joules)

% calculations
compression = force / sConstant;
pEnergy = 0.5 * (sConstant * compression ^ 2);

return