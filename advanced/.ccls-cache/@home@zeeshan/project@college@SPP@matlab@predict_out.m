function predict_out( predict, uniq_prod, file_name, file )

if nargin < 4
        
    file_name = '../output/lr_predictions.csv';
    file = '../output/extras/lr_just_pred.csv';
    
end

out = fopen(file_name, 'w');
just_data = fopen(file,'w');

fprintf(out, 'Product_Launch_Id,Weeks_Since_Launch,Units_that_sold_that_week\n');

for i = 1:length(predict)
    fprintf(out, '%d,%d,%g\n', uniq_prod(i), 26, predict(i));
    fprintf(just_data,'%g\n',predict(i));
end


end

