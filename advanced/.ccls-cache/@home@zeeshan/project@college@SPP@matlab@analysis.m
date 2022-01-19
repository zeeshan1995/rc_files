function analysis(train)

    len = length(train);
    store_26(1:len,1) = train(1:len,3);
    sales_26(1:len,1) = train(1:len,4);
    figure
    scatter(store_26,sales_26);
    xlabel("Stores");
    ylabel(" Sales ");
    hgexport(gcf,'../output/extras/analysis.jpg',hgexport('factorystyle'),'Format','jpeg');
    
    
end