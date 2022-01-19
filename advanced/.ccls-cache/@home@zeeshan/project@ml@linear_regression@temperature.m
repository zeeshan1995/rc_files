data = load('cricket_chirps_versus_temperature.txt');

x = data(:,2);
y = data(:,1);

function plotData(x, y)
  plot(x, y, 'rx', 'MarkerSize', 8);
 end
 
 plotData(x,y);
 
 xlabel('Rate of cricket chriping');
 ylabel('Temperature');
 fprintf('Program Paused.Press enter to continue\n');
 
 m = length(x);
 X = [ones(m,1) x];
 
 theta = (pinv(X'*X))*X'*y;
 
 hold on;
 plot(X(:,2),X*theta,'-')
 legend('Training data','Linear Regression');
 hold off;
  