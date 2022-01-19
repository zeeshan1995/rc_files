function x_t_cal( x , file_name)

if nargin < 2
    file_name = '../output/extras/y.csv';
end
out = fopen(file_name, 'w');

for i = 1:2767
    
        fprintf(out, '%g\n', x(i));
end
     fprintf(out, '%g', x(2768));
end