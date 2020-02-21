% task 2 lab 5
% sample the occurrence of specificed sequence in DNA
%
% sequence 1a: [AGTCACT]
% sequence 1b: AcgT
% sequence 2a: [TAC]Tga
% NOTE: [] is case insensitive
%
% simon shan



% housekeeping %
close all;
fclose all;
clear; clc;
load('DNAString.mat');


seq1a = 'AGTCACT';
seq1b = 'AcgT';
seq2a = {'TAC' , 'Tga'};



% occurence of sequence 1a
occurrence1a = length(strfind (upper(DNAString) , seq1a));
%occurrence1a = 0;

%for i = 1 : length(DNAString) - length(seq1a) + 1
    
%    dummySequence = DNAString(i : length(seq1a) + i - 1);
%    occurrence1a = occurrence1a + strcmpi(seq1a , dummySequence);
    
%end



% occurence of sequence 1b
occurrence1b = length(strfind (DNAString , seq1b));



% occurence of sequence 2a
%occurence2a = strfind (upper(DNAString) , upper([seq2a{1 : 2}])) + 3;
%occurence2a(2,1:length(occurence2a)) = occurence2a + 1;
%occurence2a(3,1:27) = occurence2a(1,1:27) + 2;
%occurence2a = transpose(occurence2a);
%part2a = DNAString(occurence2a);
%occurence2a = strfind(part2a , seq2a{2});

%occurrence2a = 0;

%for i = 1 : length(DNAString) - length([seq2a{1 : 2}]) + 1
    
%    dummySequence = DNAString(i : length(seq2a{1}) + i - 1);
%    logic = strcmpi(seq2a{1} , dummySequence);
%    dummySequence = DNAString(i + length(seq2a{1}) : length([seq2a{1 : 2}]) + i - 1);
%    logic = (logic && strcmp(seq2a{2} , dummySequence));
%    occurrence2a = occurrence2a + logic;
    
%end


% command outputs
fprintf ('sequence 1:\t');
fprintf ('sequence 2:\n');
fprintf ('a:\t%i\t'     , occurrence1a);
fprintf ('a:\t%i\n'     , occurrence2a);
fprintf ('b:\t%i\n'     , occurrence1b);
fprintf ('total:\t%i\t' , occurrence1a + occurrence1b);
fprintf ('total:\t%i\n' , occurrence2a);