
Im_name = ['1.png']; % xx������ļ�������׺������.jpgҲ������������ʽ���ļ�
for k = 1:size(Im_name,1)
    I=imread(Im_name(k,:));
%     imshow(I);
    alpha = ones(size(I,1),size(I,2));
    for i = 1 : size(I,1)
        for j = 1 :size(I,2)
            if I(i,j,1) > 250 && I(i,j,2) > 250 && I(i,j,3) > 250 %����ж���Ҫ��Ϊ��ȥ��һЩ���Ǵ��׵Ĳ���
                alpha(i,j) = 0;
            end
        end
    end
    imwrite(I,'1_2.png','Alpha',alpha);%��󱣴��,png����������ʽ���ļ�������
end


