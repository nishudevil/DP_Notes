
select first_name, last_name, email, job_success_score from
    (select p.first_name as first_name, p.last_name as last_name, p.email as email, s.job_success_score as job_success_score,
    row_number() over(order by s.job_success_score desc, p.first_name asc, p.last_name asc) rnm
    from profiles p inner join stats s
    on p.id=s.profile_id
    where  s.job_success_score >= 90
    and p.is_verified=1)
where rnm <=10;
