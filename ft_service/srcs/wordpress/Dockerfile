# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asablayr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/28 12:31:40 by asablayr          #+#    #+#              #
#    Updated: 2020/05/28 12:52:09 by asablayr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	alpine

RUN	apk update && apk add wget php-cli php-fpm php-curl php-gd php-intl && \
	wget https://wordpress.org/latest.tar.gz && \
	mv latest.tar.gz var/www/ && \
	cd var/www/ && tar -xvzf latest.tar.gz && rm -rf latest.tar.gz

COPY	srcs/wordpress/wp-config.php var/www/wordpress

#RUN	ln -s /etc/nginx/sites-available/monsite.com etc/nginx/sites-enabled/

#ENTRYPOINT	rc-service nginx start
