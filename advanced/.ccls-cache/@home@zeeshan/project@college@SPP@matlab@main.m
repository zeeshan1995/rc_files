test = importdata('../data/test.csv');
train = importdata('../data/train.csv');

%Data analysis
analysis(train.data);

%storing data of one particular product into cell
[data_train, ~, cat] = raw_to_cell(train);
[data_test, uniq_prod] = raw_to_cell(test);

%transforming data, fit for regression
[x, y] = extract(data_train);
[x_test, y_test] = extract(data_test);

lambda = 10;
%storing data
x_cal(x);
y_cal(y);
out_pid(uniq_prod);
x_t_cal(x_test);

%Split and test validation
validate(x,y,lambda)

%predicting
fit = ridge(log(y + 1), x, lambda, 0);
predict = exp([ones(size(x_test, 1), 1) x_test]*fit) - 1;

%storing the predicted data
predict_out(predict, uniq_prod);
