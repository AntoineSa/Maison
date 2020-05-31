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

RUN	apk update && apk add nginx wget php-cli php-curl php-gd php-intl php-fpm openrc

#COPY	srcs/monsite.com etc/nginx/sites-available/

#RUN	ln -s /etc/nginx/sites-available/monsite.com etc/nginx/sites-enabled/

ENTRYPOINT	rc-service nginx start
