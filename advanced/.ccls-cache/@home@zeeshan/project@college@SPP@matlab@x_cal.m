function x_cal( x , file_name)

if nargin < 2
    file_name = '../output/extras/x.csv';
end
out = fopen(file_name, 'w');

for i = 1:2768
    for j = 1 : 54
        fprintf(out, '%g,', x(i,j));
    end
        fprintf(out, '%g\n', x(i,55));
end
end