
Im_name = ['1.png']; % xx是你的文件名，后缀可以是.jpg也可以是其他形式的文件
for k = 1:size(Im_name,1)
    I=imread(Im_name(k,:));
%     imshow(I);
    alpha = ones(size(I,1),size(I,2));
    for i = 1 : size(I,1)
        for j = 1 :size(I,2)
            if I(i,j,1) > 250 && I(i,j,2) > 250 && I(i,j,3) > 250 %这个判断主要是为了去掉一些不是纯白的部分
                alpha(i,j) = 0;
            end
        end
    end
    imwrite(I,'1_2.png','Alpha',alpha);%最后保存成,png或者其他格式的文件都可以
end


