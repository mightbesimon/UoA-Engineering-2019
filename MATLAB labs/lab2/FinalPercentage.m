% This script file calculates your ENGGEN131 final percentage
% from your non-invigilated coursework (labs, assignments, projects)
% and your invigilated coursework (tests and exam)
% It will ask the user to input the marks obtained for the labs,
% assignments, projects, tests and exam
% It will then display your final mark after the ten percent rule has 
% been applied
%
% Here are some examples of inputs to try
% Scenario 1 
% Labs: 12/12, Assignments 4/4, Project 20/24
% Test1: 7/10, Test2: 0/10, Test3 :21/30, Exam 84/120
% Scenario 2   
% Labs: 12/12, Assignments 4/4, Project 24/24
% Test1: 10/10, Test2: 5/10, Test3 :30/30, Exam 45/120
% Scenario 3  
% Labs: 6/12, Assignments 2/4, Project 12/24
% Test1: 0/10, Test2: 5/10, Test3 :15/30, Exam 120/120


clear;
 
% Get non-invigilated coursework marks
% Labs are worth 12% of your final grade, assignments 4% and projects 24%.
LabMark = input('Enter lab mark out of 12 > ');
AssignmentMark = input('Enter assignments mark out of 4 > ');
ProjectMark = input('Enter projects mark out of of 24 > ');

% Get invigilated marks (i.e. tests and exam)
% Note that the two Matlab tests are worth 5% of your final grade 
% (we only count the best mark), the C test is worth 5% of your final grade
% and the exam is worth 50% of your final grade
% Test 1 and 2 are marked out of 10, test 3 out of 30
% The exam is marked out of 120
RawTest1Mark = input('Enter test 1 raw mark out of 10 > ');
RawTest2Mark = input('Enter test 2 raw mark out of 10 > ');
RawTest3Mark = input('Enter test 3 raw mark out of 30 > ');
RawExamMark = input('Enter exam raw mark out of 120> ');

% Matlab tests are worth 5%, we take the best result of the two
% (both tests are marked out of 10).
MatlabTest = 5 * max(RawTest1Mark,RawTest2Mark) / 10;
% C test is worth 5% and is marked out of 30




CTest = 5 * RawTest3Mark / 30;





% find course work mark (out of 50)
CourseWork = LabMark + AssignmentMark + ProjectMark + MatlabTest + CTest; 
 
% Find the exam percentage (out of 100) and exam mark (out of 50)
ExamPercent = RawExamMark / 120 * 100;
ExamMark = 50 * ExamPercent / 100;
% Apply 10 percent rule,
% setting the final mark to be the minimum of either
% - the exam percentage + 10
% - the combined mark (i.e. coursework worth 50% and exam worth 50%)





FinalMark = min((ExamPercent + 10),(CourseWork + ExamMark));





disp(FinalMark);