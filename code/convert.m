file_path =  '.\Repeater\';% ͼ���ļ���·��
img_path_list = dir(strcat(file_path,'*.jpg'));%��ȡ���ļ���������jpg��ʽ��ͼ��
img_num = length(img_path_list);%��ȡͼ��������
if img_num > 0 %������������ͼ��
        for j = 1:img_num %��һ��ȡͼ��
            image_name = img_path_list(j).name;% ͼ����
            pic =  imread(strcat(file_path,image_name));
            imshow(pic);
            n = graythresh(pic);     
            G = im2bw(pic,n);
            imshow(G);
            fprintf('%d %d %s\n',i,j,strcat(file_path,image_name));% ��ʾ���ڴ����ͼ����
            saveas(G,strcat(j,'_bk'),'.jpg');
            %ͼ������� ʡ��
        end
end


