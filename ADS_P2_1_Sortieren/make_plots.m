clear; clc; close all;

% Function to read data and calculate mean values in blocks of 10
function [x_mean, y_mean] = read_and_average(filename)
    fid = fopen(filename);
    data = textscan(fid, '%d %f');
    fclose(fid);
    x = data{1};
    y = data{2};
    
    % Determine the number of unique x values
    unique_x = unique(x);
    num_unique_x = numel(unique_x);
    
    % Initialize mean y values
    y_mean = zeros(num_unique_x, 1);
    
    % Calculate mean y for each unique x
    for i = 1:num_unique_x
        y_mean(i) = mean(y(x == unique_x(i)));
    end
    
    x_mean = unique_x;
end

% Define file names for each sorting algorithm
quicksort_file = 'quicksort.txt';
mergesort_file = 'mergesort.txt';
heapsort_file = 'heapsort.txt';
shellsort_file = 'shellsort_2n.txt';

% Aggregate and average the runs for each algorithm
[x_quicksort, quicksort_y] = read_and_average(quicksort_file);
[x_mergesort, mergesort_y] = read_and_average(mergesort_file);
[x_heapsort, heapsort_y] = read_and_average(heapsort_file);
[x_shellsort, shellsort_y] = read_and_average(shellsort_file);

% Plotting
figure;
title('Sorting Algorithms');
xlabel('n [-]');
ylabel('t [s]');
hold on;
plot(x_quicksort, quicksort_y, '-o');
plot(x_mergesort, mergesort_y, '-x');
plot(x_heapsort, heapsort_y, '-s');
plot(x_shellsort, shellsort_y, '-d');
legend('quicksort', 'mergesort', 'heapsort', 'shellsort', 'Location', 'northwest');

% Set axis limits to zoom in on specific range (adjust as needed)
xlim([0, 100000]);
ylim([0, 2e7]); % Adjust the y-limit as necessary

hold off;