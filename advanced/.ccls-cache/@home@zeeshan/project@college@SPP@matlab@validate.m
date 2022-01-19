function validate(x,y,lambda)


p = .8; 
N = size(x,1);  
tf = false(N,1);    
tf(1:round(p*N)) = true;     
tf = tf(randperm(N));  
dataTraining = x(tf,:);
dataTesting = x(~tf,:);
dataTraining_y = y(tf,:);
dataTesting_y = y(~tf,:);

c = ridge(log(dataTraining_y + 1), dataTraining, lambda, 0);
xx = exp([ones(size(dataTesting, 1), 1) dataTesting]*c) - 1;
figure
scatter(dataTesting_y,xx);
xlabel("True Value");
ylabel("Predictions");
hgexport(gcf,'../output/extras/lr_graph.jpg',hgexport('factorystyle'),'Format','jpeg');
end