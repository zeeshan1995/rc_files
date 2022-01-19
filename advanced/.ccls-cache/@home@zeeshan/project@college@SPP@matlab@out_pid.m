function out_pid( x , file_name)
% y_hat is the prediction, uniq_prod gives the product id for the
% respective entry of y_hat.

if nargin < 3
    file_name = '../output/extras/uniq_prod.csv';
end
out = fopen(file_name, 'w');

for i = 1:1088
    
   fprintf(out,'%g\n', x(i));
end
 fprintf(out,'%g', x(1089));
end