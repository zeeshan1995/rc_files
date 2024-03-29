function [ x, y ] = extract_features( data )

n = size(data, 1);

x = [];
y = zeros(n, 1);

for i = 1:n
    p = data{i};
    
    % 13 features: sales(week_i) / stores( week_i ) * stores( week_26 ) for
    % weeks i=1 to i=13
    x_row = [p.X(1:13, 4)./p.X(1:13, 3)*p.X(26, 3) ];
    
    % 13 features: raw sales values between weeks 1 and 13
    x_row = [ x_row; p.X(1:13,4) ];
    
    % 26 features: number of stores between weeks 1 and 26    
    x_row = [ x_row; p.X(1:26,3) ];
  
    % Take log transform of the features
    x_row = log(x_row + 1);
    
    % add some interaction terms between log-transformed features
    % 3 features: interaction terms 
    finalstores_midsales = log(p.X(26,3) + 1 ) * log(p.X(13,4) + 1);
    midz_midsales = log(p.X(13,4) / p.X(13,3) * p.X(26,3) + 1) *...
        log(p.X(13,4) + 1 );
    finalscores_midz  = log(p.X(13,4) / p.X(13,3) * p.X(26,3) + 1) *...
        log(p.X(26,3)+1);
    
    x_row = [x_row; finalstores_midsales; midz_midsales; finalscores_midz];
    
    x = [x; x_row'];
    
    y(i) = p.y;
end


end

